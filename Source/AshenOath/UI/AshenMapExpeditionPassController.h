// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMapExpeditionPassController.generated.h"

/**
 * UAshenMapExpeditionPassController
 * Controller executing Pass #2 (Expedition Pass) — rendering player-drawn travel spines, temporal visit markers (e.g. Day 14, Day 31), and graphite pins.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMapExpeditionPassController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMapExpeditionPassController();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map Pass")
	bool RenderExpeditionPass();
};
