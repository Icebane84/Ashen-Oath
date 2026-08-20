// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenTransferenceDialogueBridge.generated.h"

/**
 * UAshenTransferenceDialogueBridge
 * 
 * Injects Serafina's burnout strain and execution history into dialogue trees:
 * - "Your hands are shaking, Serafina."
 * - "I carry what you cannot, Kaelen."
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceDialogueBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTransferenceDialogueBridge();

	/** Formats dialogue reflecting companion burnout tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Transference")
	FText FormatTransferenceDialoguePrompt(
		const FString& BasePrompt,
		EBurnoutSeverityTier BurnoutTier) const;
};
