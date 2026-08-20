// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensDialogueAdapter.generated.h"

/**
 * UAshenLensDialogueAdapter
 * Modulates dialogue choice gates and companion conversational tone based on active philosophical lens.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool IsDialogueChoiceUnlocked(FName ChoiceID, EInterpretiveLens Lens);
};
