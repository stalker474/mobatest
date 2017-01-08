// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseAIController.h"
#include "MobaAIController.generated.h"

/**
 * 
 */
UCLASS()
class MOBATEST_API AMobaAIController : public ABaseAIController
{
	GENERATED_UCLASS_BODY()

public:
	/** Checks actor and returns true if valid */
	virtual bool IsTargetValid(AActor* InActor) const override;

protected:
	virtual float ComputeScore(const APawn* TestPawn) override;
	
};
