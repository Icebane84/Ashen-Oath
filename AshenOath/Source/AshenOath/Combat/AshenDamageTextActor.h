// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenDamageTextActor.generated.h"

class UTextRenderComponent;

/**
 * AAshenDamageTextActor
 * Fades and floats upward to display combat damage values.
 */
UCLASS()
class ASHENOATH_API AAshenDamageTextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAshenDamageTextActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Initialize and start display of damage text */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DamageText")
	void Activate(float Amount, FVector StartPos);

	/** Hide and stop ticking */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DamageText")
	void Deactivate();

	UFUNCTION(BlueprintPure, Category = "AshenOath|DamageText")
	bool IsActive() const { return bIsActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UTextRenderComponent* TextRender;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DamageText Settings")
	float MaxLifetime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DamageText Settings")
	float FloatSpeed;

private:
	float Lifetime;
	bool bIsActive;
};
