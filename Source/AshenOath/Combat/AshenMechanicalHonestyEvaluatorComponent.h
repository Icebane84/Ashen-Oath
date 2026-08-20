// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMechanicalHonestyEvaluatorComponent.generated.h"

/**
 * UAshenMechanicalHonestyEvaluatorComponent
 * Enforces the architectural boundary between subjective psychological interpretation (Layer 3) and objective mechanical frame data (Layer 1).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMechanicalHonestyEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMechanicalHonestyEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ValidateFrameDataIntegrity(bool bCanonicalEventRecorded, bool bCharacterBelievesInSolo);
};
