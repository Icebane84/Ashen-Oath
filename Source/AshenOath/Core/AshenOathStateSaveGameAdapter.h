// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenOathStateSaveGameAdapter.generated.h"

/**
 * UAshenOathStateSaveGameAdapter
 * Core save adapter serializing TArray<FOathRecord> into save files.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathStateSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathStateSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeOathRegistryToSave(const TArray<FOathRecord>& OathRecords);
};
