// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONYOUROWN_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
    // VARIABLES
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = 0.5;
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 0.3333;
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.0;

    
    // FUNCTIONS
    // to get the pawn controlled by this controller
    class ATank* GetControlledTank() const;

    //Moves the barrel of tank towards the looking crosshair
    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector& Out_HitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;
    bool GetLookVectorHitLocation(FVector WorldDirection, FVector& Out_HitLocation) const;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
    // called when game begins
    virtual void BeginPlay() override;
	
};
