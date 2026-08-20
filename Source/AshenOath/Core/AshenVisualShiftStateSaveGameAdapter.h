// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVisualShiftStateSaveGameAdapter.generated.h"

/**
 * UAshenVisualShiftStateSaveGameAdapter
 * Core save adapter serializing visual shift settings and shader state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVisualShiftStateSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenVisualShiftStateSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeVisualShiftState(float CorruptionIntensity, float BlendRatio);
};
