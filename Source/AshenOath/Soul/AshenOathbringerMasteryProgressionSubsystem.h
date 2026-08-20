// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenOathbringerMasteryProgressionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerMasteryUnlockedSignature, FName, MasteryNodeTag, int32, CurrentMasteryLevel);

/**
 * UAshenOathbringerMasteryProgressionSubsystem
 *
 * Subsystem tracking Oathbringer weapon proficiency and unlocking weapon masteries (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerMasteryProgressionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MasteryProgression")
	void UnlockMasteryNode(FName NodeTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MasteryProgression|Events")
	FOnOathbringerMasteryUnlockedSignature OnMasteryUnlocked;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MasteryProgression")
	int32 CurrentMasteryLevel = 1;
};
