// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRehabilitationTelemetrySaveGameAdapter.generated.h"

/**
 * UAshenRehabilitationTelemetrySaveGameAdapter
 * Core save adapter serializing purified trait counts and ritual completions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRehabilitationTelemetrySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRehabilitationTelemetrySaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeRehabilitationTelemetryToSave(int32 TotalRitualCompletionsCount);
};
