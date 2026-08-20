// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenMemoryWeavingDialogueAdapter.generated.h"

/**
 * UAshenMemoryWeavingDialogueAdapter
 * Manages companion dialogue barks during filament weaving, bridge manifestations, and thread snap emergencies.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryWeavingDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryWeavingDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerWeavingBark(EWeavingPatternType Pattern, bool bDidSnap);
};
