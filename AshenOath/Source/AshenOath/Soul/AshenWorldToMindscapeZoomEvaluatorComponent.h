// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWorldToMindscapeZoomEvaluatorComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWorldToMindscapeZoomEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWorldToMindscapeZoomEvaluatorComponent();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void UpdateMapZoomLevel(float ZoomScale);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul")
	bool IsInMindscapeConstellationMode() const { return bInMindscapeMode; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Soul")
	float GetConstellationBlendAlpha() const { return ConstellationBlendAlpha; }

private:
	bool bInMindscapeMode = false;
	float ConstellationBlendAlpha = 0.0f;
};
