// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponRuneEmissivePostProcessAdapter.generated.h"

/**
 * UAshenWeaponRuneEmissivePostProcessAdapter
 * Shimmering ancient glyph glow emanating from the player's inscribed weapon mesh.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponRuneEmissivePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeaponRuneEmissivePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyWeaponRuneEmissive(int32 RuneTier, float GlowIntensity);
};
