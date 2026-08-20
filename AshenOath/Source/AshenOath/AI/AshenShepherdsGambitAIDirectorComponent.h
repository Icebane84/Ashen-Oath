// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenShepherdsGambitAIDirectorComponent.generated.h"

/**
 * UAshenShepherdsGambitAIDirectorComponent
 * AI Director orchestrating the companion containment behavior (Garrett body block, Serafina anchor tether).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShepherdsGambitAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShepherdsGambitAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void CoordinateCompanionContainment(EUnchainedHazardLevel HazardLevel);
};
