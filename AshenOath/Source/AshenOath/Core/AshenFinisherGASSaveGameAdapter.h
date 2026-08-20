// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherGASSaveGameAdapter.generated.h"

/**
 * UAshenFinisherGASSaveGameAdapter
 * Serializes character finisher execution statistics, ability mastery levels, and unlocked synergy bonuses to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherGASSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherGASSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeFinisherGASStats(FName AbilityName, int32 ExecutionCount, bool bMastered);
};
