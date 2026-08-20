// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenAlchemicalDialogueAdapter.generated.h"

/**
 * UAshenAlchemicalDialogueAdapter
 * Manages pragmatic tactical dialogue barks for Garrett when setting traps, lighting cutlasses, or deploying smoke.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerAlchemicalBark(EAlchemicalMatrixType Type);
};
