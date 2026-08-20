// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticJournalPageTearComponent.generated.h"

/**
 * UAshenDiegeticJournalPageTearComponent
 * Triggers visual page-tear and ink-bleed effects in the diegetic journal UI upon crisis events.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticJournalPageTearComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticJournalPageTearComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void TriggerPageTear(float CrisisSeverity);
};
