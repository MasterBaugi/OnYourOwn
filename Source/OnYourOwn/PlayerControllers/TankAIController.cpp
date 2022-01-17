// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    ATank* AIControlledTank = GetAIControlledTank();
    UE_LOG(LogTemp, Warning, TEXT("AIController beginplay working"))

    if(!AIControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIC not possessing a tank"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("AIC possessing a tank: %s"), *(AIControlledTank->GetName()));
    
}

ATank* ATankAIController::GetAIControlledTank() const
{
    return Cast<ATank>(GetPawn());
}