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

    // get world location if Linetrace through crosshair
    // if hits the landscape, then move tank's barrel to that point
}
