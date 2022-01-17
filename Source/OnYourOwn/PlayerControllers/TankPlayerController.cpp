// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    ATank* ControlledTank = GetControlledTank();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController beginplay working"))

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
