// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenRemnantChroniclesSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChronicleEntryUnlockedSignature, FName, ChronicleID, int32, TotalChroniclesUnlocked);

/**
 * UAshenRemnantChroniclesSubsystem
 *
 * World Subsystem logging zone memory logs and lore chronologies discovered during exploration.
 */
UCLASS()
class ASHENOATH_API UAshenRemnantChroniclesSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|RemnantChronicles")
	bool UnlockChronicleEntry(FName ChronicleID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|RemnantChronicles")
	int32 GetUnlockedChronicleCount() const { return UnlockedChronicles.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|RemnantChronicles|Events")
	FOnChronicleEntryUnlockedSignature OnChronicleEntryUnlocked;

private:
	TSet<FName> UnlockedChronicles;
};
