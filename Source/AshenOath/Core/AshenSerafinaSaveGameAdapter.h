// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaSaveGameAdapter.generated.h"

/**
 * UAshenSerafinaSaveGameAdapter
 * Core save adapter serializing burnout level and total health transferred.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeSerafinaStateToSave(float CurrentBurnout, float TotalTransferredHP);
};
