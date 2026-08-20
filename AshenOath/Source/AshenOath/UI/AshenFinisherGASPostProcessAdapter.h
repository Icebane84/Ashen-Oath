// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherGASPostProcessAdapter.generated.h"

/**
 * UAshenFinisherGASPostProcessAdapter
 * Dual-tone golden-violet lens flare and radial motion blur during character-level finisher impacts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherGASPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherGASPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyCharacterFinisherPostProcess(FName AbilityName, float Intensity);
};
