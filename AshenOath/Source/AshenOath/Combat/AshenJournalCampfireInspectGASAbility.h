// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenJournalCampfireInspectGASAbility.generated.h"

/**
 * UAshenJournalCampfireInspectGASAbility
 * GAS Ability triggering Kaelen's campfire journal inspection animation montage.
 */
UCLASS()
class ASHENOATH_API UAshenJournalCampfireInspectGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenJournalCampfireInspectGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerJournalInspectionAtCampfire();
};
