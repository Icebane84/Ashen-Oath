// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMapGeographyPassController.generated.h"

/**
 * UAshenMapGeographyPassController
 * Controller executing Pass #1 (Geography Pass) — rendering immutable terrain, roads, outposts, elevation curves, and collision boundaries render-isolated from psychological mutations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMapGeographyPassController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMapGeographyPassController();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map Pass")
	bool RenderGeographyPass();
};
