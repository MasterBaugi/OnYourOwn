// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class ONYOUROWN_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    // to get the pawn controlled by this controller
    class ATank* GetAIControlledTank() const;

    virtual void BeginPlay() override;

};
