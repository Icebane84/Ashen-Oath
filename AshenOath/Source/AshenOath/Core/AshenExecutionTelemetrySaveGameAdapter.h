// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenExecutionTelemetrySaveGameAdapter.generated.h"

/**
 * UAshenExecutionTelemetrySaveGameAdapter
 * Core save adapter tracking total execution count and favorite stance finishers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenExecutionTelemetrySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenExecutionTelemetrySaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeExecutionTelemetryToSave(int32 TotalExecutionsCount);
};
