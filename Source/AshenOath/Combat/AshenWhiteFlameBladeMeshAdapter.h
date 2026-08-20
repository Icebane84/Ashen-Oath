// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlameBladeMeshAdapter.generated.h"

/**
 * UAshenWhiteFlameBladeMeshAdapter
 * Modulates Oathbringer weapon material instances, setting the entire greatsword blade ablaze with white-hot incandescence (4.0x emissive glow).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameBladeMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameBladeMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Visuals")
	float WhitePyreEmissiveGlow = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void SetWhiteFlameBladeState(bool bIsIgnited);
};
