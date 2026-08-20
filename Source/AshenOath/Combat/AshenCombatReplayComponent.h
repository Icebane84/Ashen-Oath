// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCombatReplayComponent.generated.h"

USTRUCT(BlueprintType)
struct FAshenCombatEvent
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Replay")
	FString EventDescription;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Replay")
	float Timestamp = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Replay")
	float DamageDealt = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeathReplayReadySignature, const TArray<FAshenCombatEvent>&, CombatLog);

/**
 * UAshenCombatReplayComponent
 *
 * Records the last 10 combat events leading to a player death and
 * broadcasts them as a death recap log for the UI. Rolling buffer,
 * max 10 entries — oldest purged when full.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatReplayComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatReplayComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Replay")
	void RecordCombatEvent(const FString& Description, float DamageDealt);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Replay")
	void TriggerDeathRecap();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Replay")
	void ClearLog();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Replay")
	const TArray<FAshenCombatEvent>& GetCombatLog() const { return CombatLog; }

	/** Max events retained in rolling buffer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Replay")
	int32 MaxLogEntries = 10;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Replay|Events")
	FOnDeathReplayReadySignature OnDeathReplayReady;

private:
	TArray<FAshenCombatEvent> CombatLog;
	float SessionStartTime = 0.0f;
};
