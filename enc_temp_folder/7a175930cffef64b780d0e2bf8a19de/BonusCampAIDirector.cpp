// Fill out your copyright notice in the Description page of Project Settings.

#include "MobaTest.h"
#include "MobaAICharacter.h"
#include "BonusCampAIDirector.h"
#include "BonusCamp.h"


// Sets default values for this component's properties
UBonusCampAIDirector::UBonusCampAIDirector(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, NextSpawnTime(0)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}


// Called when the game starts
void UBonusCampAIDirector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UBonusCampAIDirector::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetOwnerRole() == ROLE_Authority)
	{
		/*TimeSinceLastSpawn += DeltaTime;
		if (TimeSinceLastSpawn >= TimeBetweenSpawns)
		{
			TimeSinceLastSpawn = 0.0f;
			LeftToSpawn = WaveSize;
		}
		SpawnMinions();*/
	}
}

void UBonusCampAIDirector::OnGameplayStateChange(EGameplayState::Type NewState)
{
	if (NewState == EGameplayState::Playing)
	{
		Activate();
		NextSpawnTime = 0;
	}
}

void UBonusCampAIDirector::Spawn()
{
	// find best place on ground to spawn at
	const ABonusCamp* const Owner = Cast<ABonusCamp>(GetOwner());
	check(Owner);

	if (Owner->MonsterCharClass != nullptr)
	{
		FVector Loc = Owner->GetActorLocation();

		// and spawn our minion
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AMobaAICharacter* const Char = GetWorld()->SpawnActor<AMobaAICharacter>(Owner->MonsterCharClass, Loc, Owner->GetActorRotation(), SpawnInfo);
		// don't continue if he died right away on spawn
		if (Char != nullptr)
		{
			Char->SpawnDefaultController();
		}
		else
		{
			UE_LOG(LogGame, Warning, TEXT("Failed to spawn."));
		}
	}
	else
	{
		// If we dont have a class type we cannot spawn a minion. 
		UE_LOG(LogGame, Warning, TEXT("No character class specified in %s. Cannot spawn"), *Owner->GetName());
	}
}
