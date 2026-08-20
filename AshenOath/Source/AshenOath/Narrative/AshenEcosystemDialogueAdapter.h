// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenEcosystemDialogueAdapter.generated.h"

/**
 * UAshenEcosystemDialogueAdapter
 * Manages tactical dialogue calls for target swaps, crystalline plate singing, and grief-sworn echoes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEcosystemDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEcosystemDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerTargetSwapDialogue();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerHarmonicArmorCrackDialogue();
};
