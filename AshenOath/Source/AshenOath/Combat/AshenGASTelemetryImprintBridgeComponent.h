// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGASTelemetryImprintBridgeComponent.generated.h"

/**
 * UAshenGASTelemetryImprintBridgeComponent
 * Binds GAS ability execution to UAshenOath_ImprintBufferComponent.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASTelemetryImprintBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASTelemetryImprintBridgeComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GAS")
	void RecordAbilityImprint(FName AbilityID, float MemoryWeight);
};
