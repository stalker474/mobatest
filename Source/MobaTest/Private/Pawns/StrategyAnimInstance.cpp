// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MobaTest.h"
#include "StrategyAnimInstance.h"

UStrategyAnimInstance::UStrategyAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UStrategyAnimInstance::AnimNotify_Melee(UAnimNotify* Notify)
{
	// notify the pawn of the impact
	AStrategyChar* const MyChar = Cast<AStrategyChar>(TryGetPawnOwner());
	if (MyChar)
	{
		MyChar->OnMeleeImpactNotify();
	}
}
