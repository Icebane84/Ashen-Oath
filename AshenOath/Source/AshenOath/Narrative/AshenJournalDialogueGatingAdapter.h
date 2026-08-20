// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalDialogueGatingAdapter.generated.h"

/**
 * UAshenJournalDialogueGatingAdapter
 * Locks out "Vulnerable" and "Reconciliatory" dialogue choices when Guarded Friction is active, leaving only Detached/Fatalistic.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalDialogueGatingAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalDialogueGatingAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Dialogue")
	bool bAreVulnerablePathsLocked = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Dialogue")
	void UpdateDialogueGatingForJournalFriction(bool bGuardedFriction);
};
