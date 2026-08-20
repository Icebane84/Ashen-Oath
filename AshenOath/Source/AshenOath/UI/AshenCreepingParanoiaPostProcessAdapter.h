// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCreepingParanoiaPostProcessAdapter.generated.h"

/**
 * UAshenCreepingParanoiaPostProcessAdapter
 * Inverted spectral color fringes and edge darkening under high paranoia.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCreepingParanoiaPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCreepingParanoiaPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyParanoiaPostProcess(float ParanoiaIntensity);
};
