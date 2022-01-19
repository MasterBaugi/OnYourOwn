// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    ATank* ControlledTank = GetControlledTank();

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PC not possessing a tank"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("PC possessing a tank: %s"), *(ControlledTank->GetName()));
    
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrosshair();
    
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) return;
    FVector HitLocation; //Out Parameter
    if(GetSightRayHitLocation(HitLocation))
    { 
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));
     
        // if hits the landscape, then move tank's barrel to that point
    }
    
}

// get world location of Linetrace through crosshair, if line trace hits any surface then true
bool ATankPlayerController::GetSightRayHitLocation(FVector &OUT_HitLocation) const
{
    //implementing linetrace
    /*if(bSuccess)   // 
    {
        return true;
    }*/
    OUT_HitLocation = FVector(1);
    return true;
}
