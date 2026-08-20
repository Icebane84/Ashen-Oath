// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEliteInquisitionDialogueAdapter.generated.h"

/**
 * UAshenEliteInquisitionDialogueAdapter
 * Companion tactical callouts and fear reactions when facing Shroud Knights.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEliteInquisitionDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEliteInquisitionDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerEliteEncounterCallout(FName CompanionID, FName EnemyType);
};
