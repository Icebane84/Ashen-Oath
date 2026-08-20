// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenPsychologicalDialogueComponent.generated.h"

/**
 * UAshenPsychologicalDialogueComponent
 * Evaluates soul state parameters (Resolve, Corruption, Isolation) to dynamically determine dialogue tone and dialogue tree access.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychologicalDialogueComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPsychologicalDialogueComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Dialogue")
	EPsychologicalTone CurrentTone = EPsychologicalTone::Resolute;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Dialogue")
	EPsychologicalTone EvaluateDialogueTone(float Resolve, float Corruption, float Isolation);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Dialogue")
	bool CanSelectDialogueChoice(EPsychologicalTone RequiredTone, float CurrentSanity, float MinSanityRequired) const;
};
