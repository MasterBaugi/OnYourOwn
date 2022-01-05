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

public:
    // to get the pawn controlled by this controller
    class ATank* GetControlledTank() const;

    virtual void BeginPlay() override;
	
};
