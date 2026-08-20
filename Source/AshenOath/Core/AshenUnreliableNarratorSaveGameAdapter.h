// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnreliableNarratorSaveGameAdapter.generated.h"

/**
 * UAshenUnreliableNarratorSaveGameAdapter
 * Core save adapter tracking hallucination encounters and phantom kills.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNarratorSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnreliableNarratorSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeNarratorStateToSave(int32 TotalHallucinationsTriggered);
};
