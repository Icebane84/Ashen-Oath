// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenWhiteFlameSaveGameAdapter.generated.h"

/**
 * UAshenWhiteFlameSaveGameAdapter
 * Serializes White Flame history: total resolutions invoked, zones sanctified, and total debt eradicated.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveWhiteFlameTelemetry(int32 ResolutionsInvoked, int32 ZonesSanctified, float TotalDebtCleared);
};
