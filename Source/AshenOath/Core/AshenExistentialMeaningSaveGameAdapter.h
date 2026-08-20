// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenExistentialMeaningSaveGameAdapter.generated.h"

/**
 * UAshenExistentialMeaningSaveGameAdapter
 * Serializes compiled Keystone Memories, selected interpretive lenses, and historical Trial of Will choices.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenExistentialMeaningSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenExistentialMeaningSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveExistentialState(const TArray<FMemoryEchoRecord>& Memories, int32 DefianceCount, int32 WrathCount, int32 TrustCount);
};
