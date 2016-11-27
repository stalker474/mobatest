// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/PlayerState.h"
#include "MobaItem.h"

#include "MobaPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MOBATEST_API AMobaPlayerState : public APlayerState
{
	GENERATED_UCLASS_BODY()


public:
	UFUNCTION(Server, Reliable, BlueprintCallable, WithValidation, Category = "Stats")
	void LevelUp();

	UFUNCTION()
	uint8 GetTeam() const;

	UFUNCTION()
	FString GetName() const;

	UFUNCTION()
	int GetLevel() const;

	UFUNCTION()
	int GetMoney() const;

	UFUNCTION()
	int GetExperience() const;

	UFUNCTION()
	UMobaItem* GetItem(EItemSlot Slot) const;

	UFUNCTION()
	UMobaItem* GetActiveItem(EActiveItemSlot Slot) const;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Shop")
	void BuyItem(TSubclassOf<class UMobaItem> ItemClass);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Shop")
	void SellItem(EItemSlot Slot);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Shop")
	void SellActiveItem(EActiveItemSlot Slot);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Actions")
	void ActivateItem(EActiveItemSlot Slot);

	UFUNCTION()
	void EmptySlot(EItemSlot Slot);

	UFUNCTION()
	void EmptyActiveSlot(EActiveItemSlot Slot);


	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item shop")
	TArray<TSubclassOf<class UMobaItem>> AvailableItems;
protected:

	UMobaItem** GetNextEmptySlot();

	UMobaItem** GetNextActiveEmptySlot();
	
	UPROPERTY(Replicated)
	uint8 MyTeamNum;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot1;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot2;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot3;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot4;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot5;

	UPROPERTY(Replicated)
	class UMobaItem* ItemSlot6;

	UPROPERTY(Replicated)
	class UMobaItem* ActiveItemSlot1;

	UPROPERTY(Replicated)
	class UMobaItem* ActiveItemSlot2;

	UPROPERTY(Replicated)
	int Level;

	UPROPERTY(Replicated)
	int Experience;

	UPROPERTY(Replicated)
	int Money;
};
