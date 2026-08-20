// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenLootContainerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnContainerStateChangedSignature, FName, ContainerID, bool, bIsOpened);

/**
 * UAshenLootContainerSubsystem
 *
 * World subsystem managing interactive chest state persistence and world loot drop instantiation across sessions.
 */
UCLASS()
class ASHENOATH_API UAshenLootContainerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Loot")
	void RegisterContainerOpened(FName ContainerID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Loot")
	bool IsContainerOpened(FName ContainerID) const;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Loot")
	void GenerateLootDrop(FName ContainerID, FVector DropLocation);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Loot")
	TSet<FName> OpenedContainerIDs;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Loot|Events")
	FOnContainerStateChangedSignature OnContainerStateChanged;
};
