// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPurifierFlameBladeComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenPurifierBladeState : uint8
{
	Dormant,
	HolyWhiteFlame,
	SootBlackenedAsh,
	PrismaticVoid
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPurifierBladeStateChanged, EAshenPurifierBladeState, NewState);

/**
 * UAshenPurifierFlameBladeComponent
 * Governs dynamic PBR visual effects, material emissive shaders, and collision parameters of Purifier claymores.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPurifierFlameBladeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPurifierFlameBladeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Purifier Blade")
	FOnPurifierBladeStateChanged OnPurifierBladeStateChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Purifier Blade")
	EAshenPurifierBladeState BladeFlameState = EAshenPurifierBladeState::Dormant;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Purifier Blade")
	bool bIsIgnited = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Purifier Blade")
	float CalculatedHolyMultiplier = 1.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Purifier Blade")
	float FlameThermalDamage = 45.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Purifier Blade")
	void SetBladeFlameState(EAshenPurifierBladeState NewState);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Purifier Blade")
	void IgniteFlameBlade(float Duration = 10.0f);
};
