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
    // to get the pawn controlled by this controller
    class ATank* GetControlledTank() const;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    //Moves the barrel of tank towards the looking crosshair
    void AimTowardsCrosshair();


protected:
    // called when game begins
    virtual void BeginPlay() override;
	
};
