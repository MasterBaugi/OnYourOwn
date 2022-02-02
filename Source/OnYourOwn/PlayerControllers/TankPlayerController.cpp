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
        //this
        GetControlledTank()->AimAt(HitLocation);
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
    
    // Deproject the location in world
    FVector WorldDirection;
    if(GetLookDirection(ScreenLocation, WorldDirection))
    {
        // implement linetrace functionality
        GetLookVectorHitLocation(WorldDirection, Out_HitLocation);
    }

    return true;

}

// Deproject the location in world
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection);
    
}

 // implement linetrace functionality
bool ATankPlayerController::GetLookVectorHitLocation(FVector WorldDirection, FVector& Out_HitLocation) const
{
    //bool LineTraceSingleByChannel(struct FHitResult& OutHit,const FVector& Start,const FVector& End,ECollisionChannel TraceChannel,const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam) const;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (WorldDirection * LineTraceRange); 
    
    // LINETRACING
    FHitResult HitResult;
    bool bSuccess = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility);
    if(bSuccess)
    {
        Out_HitLocation = HitResult.Location;
        AActor* HitActor = HitResult.GetActor();
        UE_LOG(LogTemp, Warning, TEXT("HitActor: %s"), *(HitActor->GetName()));
        return true;
    }
    return false;
}