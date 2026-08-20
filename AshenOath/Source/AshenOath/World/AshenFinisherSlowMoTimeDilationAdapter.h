// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherSlowMoTimeDilationAdapter.generated.h"

/**
 * UAshenFinisherSlowMoTimeDilationAdapter
 * Adapter applying temporary 0.2x time dilation during execution impact frame.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherSlowMoTimeDilationAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherSlowMoTimeDilationAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ApplySlowMoTimeDilation(float DilationFactor = 0.2f, float DurationSeconds = 0.5f);
};
