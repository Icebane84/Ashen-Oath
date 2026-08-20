// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenLivingOathSaveGameAdapter.generated.h"

/**
 * UAshenLivingOathSaveGameAdapter
 * Serializes active sworn oaths, fulfillment history, and oathbreaker marks into persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingOathSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingOathSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeOathDataToSave(EAshenLivingOathType OathType, EAshenOathState State, float Fulfillment);
};
