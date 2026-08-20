// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenConstellationPerkUnlockSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationPerkUnlockedSignature, FName, NodeID, int32, TotalUnlockedNodes);

/**
 * UAshenConstellationPerkUnlockSubsystem
 *
 * World Subsystem validating prerequisites and activating nodes in Kaelen's Soul Constellation tree.
 */
UCLASS()
class ASHENOATH_API UAshenConstellationPerkUnlockSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConstellationUnlock")
	bool UnlockConstellationPerkNode(FName NodeID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ConstellationUnlock")
	int32 GetUnlockedNodeCount() const { return UnlockedNodes.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConstellationUnlock|Events")
	FOnConstellationPerkUnlockedSignature OnPerkUnlocked;

private:
	TSet<FName> UnlockedNodes;
};
