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
        //UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));
        // if hits the landscape, then move tank's turret to that point
    }
    
}

// get world location of Linetrace through crosshair, if line trace hits any surface then true
bool ATankPlayerController::GetSightRayHitLocation(FVector& Out_HitLocation) const
{
    // Find the crosshair location
    int32 ViewportSizeX;
    int32 ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    
    UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *(ScreenLocation.ToString()));

    // Deproject the location in world
    FVector WorldDirection;
    if(GetWorldDirection(ScreenLocation, WorldDirection))
    {
        UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *WorldDirection.ToString());
    }
    // Implement linetrace, and if it hits something use that hitlocation to rotate tank turret
    /*if(bSuccess)
    {
        return true;
    }*/

    return true;

}

bool ATankPlayerController::GetWorldDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection);
    
}