// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpecHandle.h"
#include "UAICognitiveComponent.generated.h"

USTRUCT(BlueprintType)
struct FAshenActionHistoryEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FGameplayTag ActionTag;

	UPROPERTY(BlueprintReadOnly)
	float Timestamp = 0.0f;
};

USTRUCT(BlueprintType)
struct FAshenThreatEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TWeakObjectPtr<APawn> ThreatTarget;

	UPROPERTY(BlueprintReadOnly)
	float ThreatScore = 0.0f;
};

/**
 * @class UAICognitiveComponent
 * @brief Ledger component: action memory, ability-completion tokens, threat
 * table storage. Deliberately does NOT perform perception or scoring — that
 * responsibility lives in UAshenOath_ThreatPerceptionComponent, which writes
 * here via UpdateThreatTable(). Keeps this component a pure data ledger with
 * a stable, minimal write API.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAICognitiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAICognitiveComponent();

	void RecordAction(const FGameplayTag& ActionTag);
	int32 GetRecentExecutionCount(const FGameplayTag& Tag, float WindowSeconds) const;

	void SetAbilityCompleted(const FGameplayAbilitySpecHandle& Handle);
	bool IsAbilityCompleted(const FGameplayAbilitySpecHandle& Handle) const;
	void ClearAbilityCompletion(const FGameplayAbilitySpecHandle& Handle);

	void UpdateThreatTable(const TArray<FAshenThreatEntry>& NewThreatEntries);
	APawn* GetPrimaryThreatTarget() const;

private:
	UPROPERTY(Transient)
	TArray<FAshenActionHistoryEntry> RecentActionJournal;

	const int32 MaxHistorySize = 8;

	UPROPERTY(Transient)
	TSet<FGameplayAbilitySpecHandle> CompletedAbilities;

	UPROPERTY(Transient)
	TArray<FAshenThreatEntry> ThreatTable;
};
