// Fill out your copyright notice in the Description page of Project Settings.

#include "OnYourOwn/Pawns/Tank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
