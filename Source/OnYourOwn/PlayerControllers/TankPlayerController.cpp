// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController beginplay working"))

    if(GetControlledTank())
    {
        UE_LOG(LogTemp, Warning, TEXT("Tank is allset"));

    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
