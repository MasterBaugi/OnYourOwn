// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    /*ATank*/auto AIControlledTank = GetAIControlledTank();

    /*ATank*/auto PlayerTank = GetPlayerTank();
    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIC cant find a tank: %s"), *(GetPlayerTank()->GetName()));
    }

    UE_LOG(LogTemp, Warning, TEXT("AIC found a tank: %s"), *(GetPlayerTank()->GetName()));
    

    if(!AIControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIC not possessing a tank"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("AIC possessing a tank: %s"), *(AIControlledTank->GetName()));
    
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    if(GetPlayerTank())
    {
        // TODO Move Towards the player

        // Aim Towards the player
        GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

        // Fire, if ready
    }
}

ATank* ATankAIController::GetAIControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    /*APlayerController*/ auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(!PlayerPawn) return nullptr;
    return Cast<ATank>(PlayerPawn);
}
