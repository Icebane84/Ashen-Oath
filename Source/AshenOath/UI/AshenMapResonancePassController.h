// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMapResonancePassController.generated.h"

/**
 * UAshenMapResonancePassController
 * Controller executing Pass #3 (Resonance Pass) — rendering Heartstone leylines, Null Zone radii, and Memory Imprint nodes fetched from UAshenOath_ImprintBufferComponent.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMapResonancePassController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMapResonancePassController();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map Pass")
	bool RenderResonancePass();
};
